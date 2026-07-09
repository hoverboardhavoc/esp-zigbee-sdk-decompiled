/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> zcl_reset_default_attr_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reset_default_attr_adapter
               (undefined4 param_1,undefined4 param_2,uint param_3,void *param_4)

{
  undefined1 uVar1;
  int iVar2;
  size_t __n;
  void *__src;
  uint local_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  
  iVar2 = ezb_zcl_get_attr_desc(0);
  if ((iVar2 != 0) && (param_4 != (void *)0x0)) {
    uStack_28 = 0;
    pvStack_24 = (void *)0x0;
    uStack_2c = param_3 & 0xffff;
    uVar1 = ezb_zcl_attr_desc_get_type();
    uStack_28 = CONCAT31(uStack_28._1_3_,uVar1);
    pvStack_24 = param_4;
    __n = ezb_zcl_get_attr_value_size(param_4);
    uStack_28 = CONCAT22((short)__n,(undefined2)uStack_28);
    local_40 = uStack_2c;
    uStack_3c = uStack_28;
    pvStack_38 = pvStack_24;
    __src = (void *)(*s_reset_default_attr_cb)(param_1,param_2,&local_40,s_reset_default_attr_cb);
    if (__src == (void *)0x0) {
      memset(param_4,0,__n);
    }
    else {
      memcpy(param_4,__src,__n);
    }
  }
  return;
}

