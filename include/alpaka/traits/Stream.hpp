/**
* \file
* Copyright 2014-2015 Benjamin Worpitz
*
* This file is part of alpaka.
*
* alpaka is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* alpaka is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with alpaka.
* If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <alpaka/core/Common.hpp>   // ALPAKA_FCT_HOST

#include <alpaka/traits/Wait.hpp>   // CurrentThreadWaitFor, WaiterWaitFor

namespace alpaka
{
    namespace traits
    {
        //-----------------------------------------------------------------------------
        //! The stream traits.
        //-----------------------------------------------------------------------------
        namespace stream
        {
            //#############################################################################
            //! The stream type trait.
            //#############################################################################
            template<
                typename TAcc>
            class GetStream;

            //#############################################################################
            //! The thread stream wait trait.
            //#############################################################################
            template<
                typename TStream, 
                typename TSfinae = void>
            struct StreamTest;
        }
    }

    //-----------------------------------------------------------------------------
    //! The stream trait accessors.
    //-----------------------------------------------------------------------------
    namespace stream
    {
        //#############################################################################
        //! The stream type trait alias template to remove the ::type.
        //#############################################################################
        template<
            typename TAcc>
        using GetStreamT = typename traits::stream::GetStream<TAcc>::type;

        //-----------------------------------------------------------------------------
        //! Tests if all operations in the given stream have been completed.
        //-----------------------------------------------------------------------------
        template<
            typename TStream>
        ALPAKA_FCT_HOST bool test(
            TStream const & stream)
        {
            return traits::stream::StreamTest<TStream>::streamTest(stream);
        }
    }
}