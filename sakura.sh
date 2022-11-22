#!/bin/bash
echo sakura
cd /root
cd new_kernel/linux-6.0.9
make -j$(nproc)
