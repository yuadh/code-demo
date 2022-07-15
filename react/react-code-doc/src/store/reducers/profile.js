const initValue = {
  user: {},
  profile: {},
}

export default function reducer(state = initValue, action) {
  const { type, payload } = action
  if (type === 'profile/user') {
    return {
      ...state,
      user: payload,
    }
  }
  if (type === 'profile/profile') {
    console.log('ppppppppp')
    return {
      ...state,
      profile: payload,
    }
  }

  return state
}
