class Node {
    constructor(value, previous = null, next = null) {
        this.value = value
        this.previous = previous
        this.next = next
    }
}

class Head extends Node {
    constructor() {
        super(null)
    }
}

class LinkedList {
    constructor() {
        this.head = new Head()
        this.length = 0
    }

    push(node) {
        if (!(node instanceof Node)) { throw 'node is not instance of Node' }
        let h = this.head
        if (h.next === null) {
            h.next = node
            node.previous = h
        } else {
            h.next.previous = node
            node.next = h.next
            h.next = node
            node.previous = h
        }
        this.length += 1
    }

    index(index) {
        if (index > this.length - 1 || index < 0) { throw 'index out of bounds' }
        let c = index
        let p = this.head.next
        while (c--) { p = p.next }
        return p
    }

    find(value) {
        let ret = []
        let p = this.head
        for (let i = 0; i < this.length; i++) {
            p = p.next
            if (p.value === value) { ret.push(i) }
        }
        return ret
    }
}

let linkedList = new LinkedList()


linkedList.push(new Node(8))
console.log(linkedList.index(0))
console.log(linkedList.find(8))

