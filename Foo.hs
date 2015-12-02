-- {-# LANGUAGE CPP #-}
{-# LANGUAGE ForeignFunctionInterface #-}
module Foo where

import Foreign.C.Types

foreign export ccall f :: CInt -> IO ()

f :: CInt -> IO ()
f = print
