/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_remove_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_remove_footer(zmsg_t *msg,uint16_t len)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint extraout_a1;
  uint uVar3;
  
  uVar2 = CONCAT22(in_register_0000202e,len);
  uVar3 = (uint)msg->tail;
  if (uVar2 <= uVar3) goto _L0;
  do {
    msg = (zmsg_t *)__assert_func(0,0,0,0);
    uVar2 = extraout_a1;
_L0:
    uVar3 = uVar3 - uVar2;
    msg->tail = (uint16_t)uVar3;
    eVar1 = zmsg_resize(msg,msg->length);
  } while (eVar1 == 1);
  return;
}

