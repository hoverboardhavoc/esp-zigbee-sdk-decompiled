/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> zcl_reset_default_attr_adapter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_reset_default_attr_adapter
               (uint8_t ep_id,uint16_t cluster_id,uint8_t cluster_role,uint16_t attr_id,
               void *attr_value)

{
  esp_zb_zcl_reset_default_attr_callback_t p_Var1;
  undefined1 uVar2;
  int iVar3;
  size_t __n;
  void *__src;
  undefined3 in_register_00002031;
  undefined1 auStack_40 [20];
  uint16_t auStack_2c [2];
  undefined2 uStack_28;
  undefined2 uStack_26;
  void *pvStack_24;
  
  iVar3 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002031,cluster_role),0);
  if ((iVar3 != 0) && (attr_value != (void *)0x0)) {
    auStack_2c[1] = 0;
    uStack_28 = 0;
    auStack_2c[0] = attr_id;
    uVar2 = ezb_zcl_attr_desc_get_type();
    __n = ezb_zcl_get_attr_value_size(attr_value);
    p_Var1 = s_reset_default_attr_cb;
    uStack_26 = (undefined2)__n;
    uStack_28 = CONCAT11(uStack_28._1_1_,uVar2);
    pvStack_24 = attr_value;
    memcpy(auStack_40,auStack_2c,0xc);
    __src = (*p_Var1)(ep_id,cluster_id,eRam00000010);
    if (__src != (void *)0x0) {
      memcpy(attr_value,__src,__n);
      return;
    }
    memset(attr_value,0,__n);
    return;
  }
  return;
}

