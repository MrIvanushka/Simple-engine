#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

namespace Engine
{
	enum MouseButton : int
	{
		LEFT = 0,
		RIGHT = 1,
		MIDDLE = 2
	};

	enum Key : int
	{
        A = 97,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        DELETE = int('\177'),
        RETURN = int('\r'),
        SCAPE = int('\033'),
        SPACE = int(' '),
        F1 = (1 << 30) | 0x3A,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        PRINTSCREEN,
        SCROLLLOCK,
        PAUSE,
        INSERT,
        HOME,
        PAGEUP,
        END = (1 << 30) | 0x4D,
        PAGEDOWN,
        RIGHTARROW,
        LEFTARROW,
        DOWNARROW,
        UPARROW,
        NUMLOCKCLEAR,
        KP_DIVIDE,
        KP_MULTIPLY,
        KP_MINUS,
        KP_PLUS,
        KP_ENTER,
        KP_1,
        KP_2,
        KP_3,
        KP_4,
        KP_5,
        KP_6,
        KP_7,
        KP_8,
        KP_9,
        KP_0,
        KP_PERIOD,
        LSHIFT = (1 << 30) | 0xE1,
        ALT = 0x0100 | 0x0200,
        CTRL = 0x0040 | 0x0080,
        GUI = 0x0400 | 0x0800,
        SHIFT = 0x0001 | 0x0002,
        NUM = 0x1000,
	};

	class Input
	{
	public:
		virtual ~Input() = default;

		virtual bool keyPressed(Key key) const = 0;
		virtual bool keyReleased(Key key) const = 0;
		virtual bool mouseMoved(glm::vec2& delta) const = 0;
		virtual bool mouseButtonPressed(MouseButton button) const = 0;
		virtual bool mouseButtonReleased(MouseButton button) const = 0;
        virtual bool keyHolding(Key key) const = 0;
        virtual bool mouseButtonHolding(MouseButton button) const = 0;
        virtual glm::vec2 mousePosition() const = 0;
	};
}

#endif //ENGINE_TRANSFORM_H
