/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t time_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  zcl_attr_desc_t *pzVar2;
  byte *pbVar3;
  
  uVar1 = CONCAT22(in_register_0000202a,attr_id);
  pzVar2 = time_server_get_attr_desc(endpoint,1);
  if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (pbVar3 = (byte *)pzVar2->data_p, pbVar3 == (byte *)0x0)
     ) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/time.c",0xe7,
                  "time_cluster_srv_check_value_handler",0x10170);
  }
  else {
    if (uVar1 == 1) {
                    /* WARNING: Load size is inaccurate */
      if (((*value ^ *pbVar3) & 5) == 0) {
        return (*value ^ *pbVar3) & 5;
      }
      return 0x88;
    }
    if (1 < uVar1) {
      if (3 < (uVar1 - 2 & 0xffff)) {
        return '\0';
      }
      if ((*pbVar3 & 4) == 0) {
                    /* WARNING: Load size is inaccurate */
        if (*value != -1) {
          return *pbVar3 & 4;
        }
        return 0x87;
      }
      return 0x88;
    }
    if (uVar1 == 0) {
      if ((*pbVar3 & 1) != 0) {
        return 0x88;
      }
                    /* WARNING: Load size is inaccurate */
      if (*value != -1) {
        return *pbVar3 & 1;
      }
      return 0x87;
    }
  }
  return '\0';
}

