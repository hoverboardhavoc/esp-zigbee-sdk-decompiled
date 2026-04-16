/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_check_options_is_exec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool color_control_check_options_is_exec(uint8_t ep_id,uint8_t mask,uint8_t override)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  byte bVar4;
  
  pzVar2 = color_control_srv_get_attr_desc(ep_id,0xf);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    bVar4 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    bVar4 = *pzVar2->data_p;
    if ((mask & 1) != 0) {
      if ((override & 1) == 0) {
        bVar4 = 0;
      }
      else {
        bVar4 = bVar4 | 1;
      }
    }
  }
  iVar3 = zcl_get_cluster_desc(CONCAT31(in_register_00002029,ep_id),6,1);
  if (iVar3 == 0) {
    _Var1 = true;
  }
  else {
    iVar3 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),6,1,0,0);
    if (iVar3 == 0) {
      _Var1 = true;
    }
    else if (**(char **)(iVar3 + 8) == '\0') {
      if ((bVar4 & 1) == 0) {
        _Var1 = false;
      }
      else {
        _Var1 = true;
      }
    }
    else {
      _Var1 = true;
    }
  }
  return _Var1;
}

