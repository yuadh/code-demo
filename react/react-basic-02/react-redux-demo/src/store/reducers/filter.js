export default function filter(state = 'all', action) {
  const { type, payload } = action
  switch (type) {
    case 'CHANGE_STAGE':
      return payload
    default:
      return state
  }
}
