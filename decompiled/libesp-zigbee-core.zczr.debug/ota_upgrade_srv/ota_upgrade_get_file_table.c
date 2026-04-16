/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_get_file_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ota_upgrade_file_table_t * ota_upgrade_get_file_table(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  ota_upgrade_file_table_t *poVar2;
  short *psVar3;
  char *pcVar4;
  short sVar5;
  
  pzVar1 = ota_upgrade_srv_get_attr_desc(ep_id,0xeff1);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    return (ota_upgrade_file_table_t *)pzVar1->data_p;
  }
  pcVar4 = "ota_upgrade_get_file_table";
  psVar3 = (short *)__assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                                  0x6b,"ota_upgrade_get_file_table","file_table_attr_desc");
  poVar2 = (ota_upgrade_file_table_t *)zmsg_read_bytes(*psVar3,1,pcVar4);
  if (poVar2 == (ota_upgrade_file_table_t *)0x0) {
    sVar5 = -1;
  }
  else {
    sVar5 = *psVar3 + (short)poVar2;
  }
  *psVar3 = sVar5;
  return poVar2;
}

