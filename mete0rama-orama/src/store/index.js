import Vue from 'vue'
import Vuex from 'vuex'
import axios from 'axios'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    measurements: [],
    stationEndpoint: ''
  },
  mutations: {
    SET_MEASUREMENTS (state, measurements) {
      state.measurements = measurements
    },
    SET_ENDPOINT (state, url) {
      state.stationEndpoint = url
    }
  },
  actions: {
    async fetchMeasurements ({ commit, state }) {
      const endpoint = state.stationEndpoint
      if (endpoint !== '') {
        axios
          .get(endpoint)
          .then(response => {
            commit('SET_MEASUREMENTS', response.data.data)
            return Promise.resolve()
          })
      }
      return Promise.reject(new Error('Cannot fetch measurements until URL is set'))
    },
    async fetchStationURL ({ commit }) {
      const lsUrl = window.localStorage.getItem('stationUrl')
      if (lsUrl) {
        commit('SET_ENDPOINT', lsUrl)
        return Promise.resolve()
      }
      return Promise.reject(new Error('No URL set'))
    },
    async setStationUrl ({ dispatch }, url) {
      window.localStorage.setItem('stationUrl', url)
      dispatch('fetchStationURL')
    }
  },
  modules: {
  }
})
