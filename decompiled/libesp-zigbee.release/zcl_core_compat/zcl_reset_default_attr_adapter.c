/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> zcl_reset_default_attr_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reset_default_attr_adapter
               (undefined4 param_1,undefined4 param_2,undefined2 param_3,void *param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  size_t __n;
  void *__src;
  undefined1 auStack_40 [20];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  void *pvStack_24;
  
  iVar3 = ezb_zcl_get_attr_desc(0);
  if ((iVar3 != 0) && (param_4 != (void *)0x0)) {
    uStack_2a = 0;
    uStack_28 = 0;
    uStack_2c = param_3;
    uVar2 = ezb_zcl_attr_desc_get_type();
    __n = ezb_zcl_get_attr_value_size(param_4);
    pcVar1 = s_reset_default_attr_cb;
    uStack_26 = (undefined2)__n;
    uStack_28 = CONCAT11(uStack_28._1_1_,uVar2);
    pvStack_24 = param_4;
    memcpy(auStack_40,&uStack_2c,0xc);
    __src = (void *)(*pcVar1)(param_1,param_2,auStack_40);
    if (__src != (void *)0x0) {
      memcpy(param_4,__src,__n);
      return;
    }
    memset(param_4,0,__n);
    return;
  }
  return;
}

