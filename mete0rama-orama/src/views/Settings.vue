<template>
  <div class="settings">
    <h1>Settings</h1>

    <section>
      <h2>Station URL</h2>
      <div v-if="hasStationURL">
        <p>You're currently fetching from {{stationURL}}</p>
        <button type="button" v-on:click="toggleForm">Change URL</button></div>
      <div v-else>Please configure a station URL</div>

      <div v-if="displayingForm">
        <label>
          <span>Enter the URL of the station API</span>
          <input type="text"
                 id="settings-url"
                 placeholder="http://192.168.178.42/data"
                 :value="stationURL"
                 @input="updateUrl">
        </label>
        <p class="form-help">This is the data endpoint that your Mete0rama station exposes in your home network.</p>
      </div>
    </section>
  </div>
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
      if (!this.hasStationURL) {
        return true
      } else {
        return this.isDisplayingForm
      }
    }
  }
}
</script>

<style scoped lang="scss">
  label {
  color: inherit;
    span {
      display: block;
    }
  }
  input {
  &::placeholder {
    color: #ccc;
  }
    display: block;
    font: inherit;
    padding: 0.3em .2em;
    margin-bottom: .5em;
  }
  .form-help {
    margin: 0;
    color: #999;
    font-size: 1.2rem;
  }
</style>
