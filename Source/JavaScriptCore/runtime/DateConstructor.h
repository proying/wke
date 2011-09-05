/*
 *  Copyright (C) 1999-2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2008, 2011 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef DateConstructor_h
#define DateConstructor_h

#include "InternalFunction.h"

namespace JSC {

    class DatePrototype;

    class DateConstructor : public InternalFunction {
    public:
        typedef InternalFunction Base;

        static DateConstructor* create(ExecState* exec, JSGlobalObject* globalObject, Structure* structure, DatePrototype* datePrototype)
        {
            return new (allocateCell<DateConstructor>(*exec->heap())) DateConstructor(exec, globalObject, structure, datePrototype);
        }

        static const ClassInfo s_info;

        static Structure* createStructure(JSGlobalData& globalData, JSValue prototype)
        {
            return Structure::create(globalData, prototype, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
        }

    protected:
        static const unsigned StructureFlags = OverridesGetOwnPropertySlot | InternalFunction::StructureFlags;

    private:
        DateConstructor(ExecState*, JSGlobalObject*, Structure*, DatePrototype*);
        virtual ConstructType getConstructData(ConstructData&);
        virtual CallType getCallData(CallData&);

        virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
        virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    };

    JSObject* constructDate(ExecState*, JSGlobalObject*, const ArgList&);

} // namespace JSC

#endif // DateConstructor_h
