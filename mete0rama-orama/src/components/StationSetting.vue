<template>
  <section>
    <h2 class="settings-header">Station URL</h2>
    <p class="form-help">This is the data endpoint that your Mete0rama station exposes in your home network.</p>
    <div>
      <p v-if="hasStationURL">You're currently fetching from</p>
      <p v-else>Please enter a station URL</p>
    </div>

    <div v-if="displayingForm" class="form-item">
      <label>
        <span>Station URL</span>
        <input type="text"
               id="settings-url"
               placeholder="http://192.168.178.42/data"
               :value="stationURL"
               @input="updateUrl">
      </label>
      <button type="button"
              v-on:click="toggleForm">Done!</button>
    </div>
    <div v-else>
      <p><span class="highlight">{{stationURL}}</span></p>
    </div>
    <button type="button"
            v-show="!displayingForm"
            v-on:click="toggleForm">Update</button>

  </section>
</template>

<script>
import { mapState } from 'vuex'

export default {
  components: {},
  data () {
    return {
      isDisplayingForm: false
    }
  },
  methods: {
    toggleForm () {
      this.isDisplayingForm = !this.isDisplayingForm
    },
    updateUrl (e) {
      this.$store.dispatch('setStationUrl', e.target.value)
    }
  },
  computed: {
    ...mapState(['stationEndpoint']),
    hasStationURL () {
      return this.stationEndpoint !== ''
    },
    stationURL () {
      return this.stationEndpoint
    },
    displayingForm () {
      return this.isDisplayingForm
    }
  }
}
</script>
