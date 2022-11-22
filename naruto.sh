#!/bin/bash
echo naruto
cd /root
cd new_kernel/linux-6.0.9
make -j$(nproc)
