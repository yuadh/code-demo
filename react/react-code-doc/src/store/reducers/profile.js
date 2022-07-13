const initValue = {
  user: {},
}

export default function reducer(state = initValue, action) {
  const { type, payload } = action
  if (type === 'profile/user') {
    return {
      ...state,
      user: payload,
    }
  }
  return state
}
