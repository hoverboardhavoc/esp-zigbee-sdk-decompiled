/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> basic_input_output_value.o -> multistate_basic_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
multistate_basic_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  byte bVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  byte bVar3;
  
  iVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (iVar2 == 0x51) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *value;
    bVar3 = 1;
  }
  else {
    if (iVar2 != 0x6f) {
      if (iVar2 != 0x4a) {
        return '\0';
      }
                    /* WARNING: Load size is inaccurate */
      return (-(*value != 0) & 0x79U) + 0x87;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = *value;
    bVar3 = 0xf;
  }
  return -(bVar3 < bVar1) & 0x87;
}

