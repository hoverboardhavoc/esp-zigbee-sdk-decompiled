/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_get_file_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_get_file_table(void)

{
  int iVar1;
  short *psVar2;
  char *pcVar3;
  short sVar4;
  
  iVar1 = ota_upgrade_srv_get_attr_desc(0xeff1);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 8);
  }
  pcVar3 = "ota_upgrade_get_file_table";
  psVar2 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c"
                                  ,0x6b,"ota_upgrade_get_file_table","file_table_attr_desc");
  iVar1 = zmsg_read_bytes(*psVar2,1,pcVar3);
  if (iVar1 == 0) {
    sVar4 = -1;
  }
  else {
    sVar4 = *psVar2 + (short)iVar1;
  }
  *psVar2 = sVar4;
  return iVar1;
}

