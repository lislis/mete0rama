<template>
<div class="home">
  <div class="phenomena">
    <Phenomenon v-for="measurement in measurements"
                :key="measurement.type"
                :phenomenon="measurement"></Phenomenon>
  </div>
</div>
</template>

<style scoped lang="scss">
  .phenomena {
  display: flex;
  flex-flow: wrap;
  justify-content: space-between;
  }
</style>

<script>
import Phenomenon from './../components/Phenomenon'

export default {
  name: 'Home',
  components: {
    Phenomenon
  },
  computed: {
    measurements () {
      return this.$store.state.measurements
    }
  }
}
</script>
