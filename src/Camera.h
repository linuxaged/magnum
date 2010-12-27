#ifndef Magnum_Camera_h
#define Magnum_Camera_h
/*
    Copyright © 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

/** @file
 * @brief Class Magnum::Camera
 */

#include "AbstractObject.h"

namespace Magnum {

/**
 * @brief Camera object
 *
 * @todo Subclasses - perspective, FBO postprocessing etc.
 */
class Camera: public AbstractObject {
    public:
        /** @copydoc AbstractObject::AbstractObject() */
        inline Camera(AbstractObject* parent = 0): AbstractObject(parent) {}

        /**
         * @brief Camera matrix
         *
         * Camera matrix describes world position relative to the camera and is
         * applied as first.
         */
        Matrix4 cameraMatrix() const;

        /**
         * @brief Projection matrix
         *
         * Projection matrix handles e.g. perspective distortion and is applied
         * as last.
         */
        virtual inline Matrix4 projectionMatrix() const { return Matrix4(); }

        /**
         * @brief Set viewport
         * @param width     Window / buffer width
         * @param height    Window / buffer height
         *
         * Called when assigning the camera to the scene or when window
         * size changes. Default implementation preserves aspect ratio and
         * sets viewport to whole window / buffer size.
         */
        virtual void setViewport(int width, int height);

        /**
         * @brief Draw camera
         *
         * Subclasses can draw for example an HUD. Default implementation does
         * nothing.
         */
        virtual void draw(const Magnum::Matrix4& transformationMatrix, const Magnum::Matrix4& projectionMatrix) {}
};

}

#endif
