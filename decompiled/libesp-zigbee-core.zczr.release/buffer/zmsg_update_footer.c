/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_update_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void zmsg_update_footer(zmsg_t *msg,void *obj,uint16_t len)

{
  buffer_t *pbVar1;
  buffer_t *pbVar2;
  buffer_t *buf;
  void *extraout_a1;
  undefined2 in_register_00002032;
  size_t __n;
  uint uVar3;
  
  __n = CONCAT22(in_register_00002032,len);
  uVar3 = (uint)msg->tail;
  if (uVar3 < __n) {
    __n = 0;
    msg = (zmsg_t *)__assert_func(0,0,0);
    obj = extraout_a1;
  }
  pbVar2 = msg->chunks;
  buf = msg->chunks;
  while (pbVar1 = pbVar2, pbVar1 != (buffer_t *)0x0) {
    buf = pbVar1;
    pbVar2 = *(buffer_t **)&pbVar1->field_0;
  }
  if (0xac < uVar3) {
    buf = (buffer_t *)buffer_get_tail(buf,(uint16_t)obj);
  }
  memcpy((void *)((int)buf + (0xb0 - uVar3)),obj,__n);
  return;
}

