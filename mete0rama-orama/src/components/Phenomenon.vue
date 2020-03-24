<template>
  <div class="phen">
    <h2 class="phen-type">{{ phenomenon.type }}</h2>
    <p class="phen-body">
      <img  class="icon"
            :src="iconSource"
            alt="icon" />
      <span class="phen-value">{{ phenomenon.value.toFixed(1) }}</span>
      <span class="phen-unit">{{ phenomenon.unit }}</span>
    </p>

  </div>
</template>

<script>
export default {
  name: 'Phenomenon',
  props: {
    phenomenon: Object
  },
  computed: {
    iconSource () {
      return require(`../assets/icons/${this.phenomenon.type}.svg`)
    }
  }
}
</script>

<style scoped lang="scss">
  .phen {
  flex: 1 1 30rem;
  display: flex;
  flex-flow: row wrap;
  align-items: center;
  margin-bottom: 5rem;
  }
  .phen-type {
  flex: 1 0 100%;
  order: 1;
  margin: 0;
  font-size: 2rem;
  text-transform: uppercase;
  color: #ccc;
  }
  .phen-body {
  margin: 0;
  }
  .phen-value {
  display: inline-block;
  margin-right: 0.5rem;
  font-size: 5rem;
  }
  .phen-unit {
  display: inline-block;
  font-size: 2rem;
  }
  .icon {
  height: 4rem;
  width: 4rem;
  text-align: center;
  margin-right: 2rem;
  opacity: 0.8;

  }
</style>
