import Vue from 'vue'
import App from './App.vue'
import './registerServiceWorker'
import router from './router'
import store from './store'
import axios from 'axios'

Vue.config.productionTip = false

new Vue({
  router,
  store,
  mounted () {
    axios
      .get('http://192.168.178.42/data')
      .then(response => {
        store.commit('updateMeasurements', response.data.data)
      })
  },

  render: h => h(App)
}).$mount('#app')
