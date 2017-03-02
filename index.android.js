'use strict';

import React from 'react';
import {
	AppRegistry,
	StyleSheet,
	Button,
	Text,
	Image,
	View
} from 'react-native';
import { startGame } from './react/gamestarter';

const onButtonPress = () => {
	startGame((response) => {
		console.log('response = ', response);
	});
};

class GameMenu extends React.Component {
	render() {
		return (
			<Image source={require('./react/images/main_menu_bg.png')} style={styles.container}>
				<View style={styles.aboveButtons}>
				</View>

				<Text style={styles.hello}>Main Menu</Text>

				<View style={styles.buttons}>
					<View style={styles.buttonSplit}>
					</View>

					<View style={styles.buttonSplit}>
						<Button style={styles.button}
							onPress={onButtonPress}
							title='Start Game'
						/>
						<Text style={{height: 4}}> </Text>
						<Button style={styles.button}
							onPress={onButtonPress}
							title='Place Holder 1'
						/>
						<Text style={{height: 4}}> </Text>
						<Button style={styles.button}
							onPress={onButtonPress}
							title='Place Holder 2'
						/>
					</View>
				</View>

				<View style={styles.belowButtons}>
				</View>
			</Image>
		)		
	}
}

var styles = StyleSheet.create({
	container: {
		flex: 1,
		height: null,
		width: null,
		justifyContent: 'center',
	},
	hello: {
		fontSize: 20,
		textAlign: 'center',
		margin: 10,
	},
	aboveButtons: {
		flex: 0.4,
	},
	buttons: {
		flex: 0.2,
		flexDirection: 'row',
		justifyContent: 'center',
	},
	buttonSplit: {
		flex: 0.5,
	},
	button: {
		fontSize: 20,
		textAlign: 'center',
		margin: 10,
		backgroundColor: '#4EA0DF',
	},
	belowButtons: {
		flex: 0.4,
	},
});

AppRegistry.registerComponent('GameMenu', () => GameMenu);

