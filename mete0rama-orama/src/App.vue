<template>
<div id="app">
  <header class="header">
    <h1 class="app-title">Mete0rama</h1>
    <div class="nav">
      <router-link to="/" title="Home">
        <img svg-inline class="icon" src="./assets/icons/home-solid.svg" alt="home" />
      </router-link>
      <router-link to="/settings" title="Settings">
        <img svg-inline class="icon" src="./assets/icons/cog-solid.svg" alt="settings" />
      </router-link>
    </div>
  </header>
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

html {
  font-size: 1rem;
  @media (max-width: 560px) {
    font-size: 0.7rem;
  }
}

body {
  background-color: #e6e6e6;
}

#app {
  max-width: 65rem;
  margin: auto;
  font-size: 1.6rem;
  color: #333;
  font-family: Chunk, serif;
  @media (max-width: 65rem) {

  }
}

.app-title {
  font-size: 4rem;
}

.header {
  display: flex;
  align-items: baseline;
  flex-wrap: wrap;
  justify-content: space-between;
  margin-bottom: 2rem;
}

.nav {
  display: flex;
  align-content: center;
  justify-content: space-between;
  margin-bottom: 4rem;
  flex: 0 0 6rem;
  .icon {
    width: 2rem;
    height: 2rem;
    opacity: 0.8;
  }
  a {
    display: block;
    padding: 0.5em;
    line-height: 1;
    border-radius: 10px;
    &.router-link-exact-active {
      background-color: #ccc;
    }
  }
}
</style>
