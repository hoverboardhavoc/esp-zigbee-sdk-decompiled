/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_add_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t zmsg_add_footer(zmsg_t *msg,void *obj,uint16_t len)

{
  buffer_t *pbVar1;
  buffer_t *pbVar2;
  buffer_t *pbVar3;
  uint uVar4;
  uint uVar5;
  ezb_err_t eVar6;
  void *extraout_a1;
  undefined2 in_register_00002032;
  size_t __n;
  
  __n = CONCAT22(in_register_00002032,len);
  uVar4 = msg->tail + __n;
  uVar5 = uVar4 & 0xffff;
  if (0xac < uVar5) {
    __n = 0;
    msg = (zmsg_t *)__assert_func(0,0,0);
    obj = extraout_a1;
  }
  eVar6 = zmsg_resize(msg,msg->length + (short)__n);
  if (eVar6 == 0) {
    msg->tail = (uint16_t)(uVar4 * 0x10000 >> 0x10);
    pbVar3 = msg->chunks;
    pbVar2 = msg->chunks;
    while (pbVar1 = pbVar3, pbVar1 != (buffer_t *)0x0) {
      pbVar2 = pbVar1;
      pbVar3 = *(buffer_t **)&pbVar1->field_0;
    }
    memcpy((void *)((int)pbVar2 + (0xb0 - uVar5)),obj,__n);
  }
  return eVar6;
}

