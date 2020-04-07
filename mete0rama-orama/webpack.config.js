// vue-cli, gridsome, quasar

module.exports = {
	chainWebpack: config => {
		config.module
			.rule("vue")
			.use("vue-svg-inline-loader")
			.loader("vue-svg-inline-loader")
			.options({ /* ... */ });
	}
};
