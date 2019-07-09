{
	let r := 0
	for { let i := 0 } lt(i, 1000000) { i := add(i, 1) } {

		0x17911de2684a20a4
		0xc69aa81c2a42361a
		0x17911de2684a20a4
		
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		pop
		dup2
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop
		dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop dup2 pop

		=: r
		pop
		pop
	}
	switch r
	case 0x17911de2684a20a4 {
		stop
	}
	default {
		0
		0
		revert
	}
}
