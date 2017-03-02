import { NativeModules } from 'react-native'

export const startGame = (callback) => {
  NativeModules.GameLauncher.startGame(callback)
}
