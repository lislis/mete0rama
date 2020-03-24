<template>
  <div class="home">
    {{ measurements.temperature }}
 </div>
</template>

<script>
// @ is an alias to /src

export default {
  name: 'Home',
  components: {
  },
  computed: {
    measurements () {
      return this.$store.state.measurements
    }
  }
}
</script>
