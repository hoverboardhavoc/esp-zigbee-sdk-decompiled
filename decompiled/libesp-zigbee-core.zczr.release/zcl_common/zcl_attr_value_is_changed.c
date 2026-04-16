/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_attr_value_is_changed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_attr_value_is_changed(zcl_attr_desc_t *attr_desc,void *new_value)

{
  _Bool _Var1;
  uint16_t uVar2;
  undefined2 extraout_var_00;
  size_t sVar3;
  undefined3 extraout_var;
  int iVar4;
  zcl_attr_type_t attr_type;
  uint uVar5;
  uint8_t auStack_28 [4];
  uint8_t new_val_buf [8];
  size_t __n;
  undefined2 extraout_var_01;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    return false;
  }
  if (new_value != (void *)0x0) {
    uVar2 = zcl_get_attr_value_size(attr_desc->type,attr_desc->data_p);
    __n = CONCAT22(extraout_var_00,uVar2);
    uVar2 = zcl_get_attr_value_size(attr_desc->type,new_value);
    sVar3 = CONCAT22(extraout_var_01,uVar2);
    if ((__n != 0xffff) && (sVar3 != 0xffff)) {
      attr_type = attr_desc->type;
      _Var1 = zcl_attr_type_is_composite(attr_type);
      uVar5 = CONCAT31(extraout_var,_Var1);
      if (uVar5 == 0) {
        auStack_28[0] = '\0';
        auStack_28[1] = '\0';
        auStack_28[2] = '\0';
        auStack_28[3] = '\0';
        new_val_buf[0] = '\0';
        new_val_buf[1] = '\0';
        new_val_buf[2] = '\0';
        new_val_buf[3] = '\0';
        if (__n != sVar3) {
          attr_type = '\0';
          __assert_func(0,0);
        }
        zcl_write_attr_value(auStack_28,new_value,attr_type);
        new_value = auStack_28;
      }
      else if (__n != sVar3) goto _L0;
      iVar4 = memcmp(attr_desc->data_p,new_value,__n);
      uVar5 = (uint)(iVar4 != 0);
      goto _L0;
    }
  }
  uVar5 = 0;
_L0:
  return SUB41(uVar5,0);
}

