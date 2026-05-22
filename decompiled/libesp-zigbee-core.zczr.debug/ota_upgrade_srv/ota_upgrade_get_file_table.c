/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  psVar3 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c"
                                  ,0x6b,"ota_upgrade_get_file_table","file_table_attr_desc");
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

