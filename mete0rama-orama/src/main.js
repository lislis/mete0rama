import Vue from 'vue'
import App from './App.vue'
import './registerServiceWorker'
import router from './router'
import store from './store'

Vue.config.productionTip = false

new Vue({
  router,
  store,
  mounted () {
    store.dispatch('fetchStationURL').then(() => {
      store.dispatch('fetchMeasurements')
    })
  },
  render: h => h(App)
}).$mount('#app')
