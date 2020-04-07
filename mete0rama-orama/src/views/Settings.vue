<template>
  <div class="settings">
    <h1>Settings</h1>
    <StationSetting />
  </div>
</template>

<script>
import StationSetting from '../components/StationSetting.vue'

export default {
  components: { StationSetting }
}
</script>

<style lang="scss">
  .settings-header {
    margin-top: 4rem;
    margin-bottom: .5em;
    border-bottom: 2px solid #999;
  }
  .settings-note {
    padding: 0.8rem;
    background-color: #ccc;
  }

  label {
    color: #999;
    font-size: 1rem;
    text-transform: uppercase;
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
    font-size: 1.6rem;
    padding: 0.3em .2em;
    margin-bottom: .5em;
  }
  .form-help {
    margin: 0;
    color: #999;
    font-size: 1.6rem;
  }
  .form-item {
    margin-top: 1rem;
  }
  button {
    font: inherit;
    padding: .4em 1em;
    background-color: #999;
    color: #e6e6e6;
    border: none;
    cursor: pointer;
    transition: background-color 200ms ease-in-out;
    &:hover {
      background-color: #333;
    }
  }
</style>
