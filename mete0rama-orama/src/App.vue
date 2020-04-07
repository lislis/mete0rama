<template>
<div id="app">
  <h1 class="app-title">Mete0rama</h1>
    <div id="nav">
      <router-link to="/">Home</router-link> |
      <router-link to="/settings">Settings</router-link>
    </div>
    <router-view/>
    <AppFooter/>
  </div>
</template>

<script>
import AppFooter from './components/AppFooter'

export default {
  name: 'App',
  components: {
    AppFooter
  }
}

</script>

<style lang="scss">
@font-face {
  font-family: "Chunk";
  src: url("assets/chunk-master/webfonts/ChunkFive-Regular.woff2") format("woff2"),
       url("assets/chunk-master/webfonts/ChunkFive-Regular.woff") format('woff');
  font-weight: normal;
  font-style: normal;
}

body {
  background-color: #e6e6e6;
}

#app {
  max-width: 70rem;
  margin: auto;
  font-size: 1.6rem;
  color: #333;
  font-family: Chunk, serif;
}

.app-title {
  font-size: 4rem;
}

#nav {

  a {
    font-weight: bold;
    color: #2c3e50;

    &.router-link-exact-active {
      color: #42b983;
    }
  }
}
</style>
