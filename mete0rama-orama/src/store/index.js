import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    measurements: {}
  },
  mutations: {
    updateMeasurements (state, measurements) {
      state.measurements = measurements
    }
  },
  actions: {
  },
  modules: {
  }
})
