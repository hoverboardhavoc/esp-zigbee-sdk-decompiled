/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> dehumidification_control.o -> dehumidification_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
dehumidification_control_cluster_srv_check_value_handler
          (uint16_t attr_id,uint8_t endpoint,void *value)

{
  byte bVar1;
  bool bVar2;
  undefined2 in_register_0000202a;
  uint uVar3;
  int iVar4;
  undefined3 in_register_0000202d;
  
  uVar3 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar3 == 0x13) {
                    /* WARNING: Load size is inaccurate */
    bVar2 = *value - 2 < 0x13;
_L0:
    bVar1 = bVar2 ^ 1;
  }
  else {
    if (uVar3 < 0x14) {
      if (uVar3 == 1) {
        iVar4 = zcl_get_attr_desc(CONCAT31(in_register_0000202d,endpoint),0x203,1,0x14,0);
        if ((iVar4 != 0) && (*(byte **)(iVar4 + 8) != (byte *)0x0)) {
                    /* WARNING: Load size is inaccurate */
          return **(byte **)(iVar4 + 8) < *value;
        }
      }
      else if (uVar3 == 0x10) {
                    /* WARNING: Load size is inaccurate */
        bVar2 = *value - 0x1e < 0x47;
        goto _L0;
      }
    }
    else if (uVar3 == 0x14) {
                    /* WARNING: Load size is inaccurate */
      bVar2 = *value - 0x14 < 0x51;
      goto _L0;
    }
    bVar1 = 0;
  }
  return bVar1;
}

