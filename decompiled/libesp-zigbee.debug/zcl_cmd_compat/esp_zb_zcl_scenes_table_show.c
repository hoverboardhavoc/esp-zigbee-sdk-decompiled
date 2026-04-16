/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zcl_scenes_table_show(uint8_t ep_id)

{
  undefined4 *puVar1;
  int iVar2;
  undefined3 in_register_00002029;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),5,1,0xeff1,0x131b);
  if (iVar3 != 0) {
    pbVar4 = *(byte **)(iVar3 + 8);
    puts("+-------+----------+----------+-----------------+-------------------------------------+");
    puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extension Field]    |");
    puts("+-------+----------+----------+-----------------+-------------------------------------+");
    for (iVar3 = 0; iVar3 < (int)(uint)*pbVar4; iVar3 = iVar3 + 1) {
      if (pbVar4[iVar3 * 0x20 + 8] != 0) {
        printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
        for (puVar1 = *(undefined4 **)(pbVar4 + iVar3 * 0x20 + 0x24); puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          printf(" [ 0x%04x |");
          if ((*(char *)((int)puVar1 + 6) != '\0') && (puVar1[2] != 0)) {
            for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)((int)puVar1 + 6); iVar2 = iVar2 + 1) {
              printf(" 0x%x ");
            }
          }
          printf("] |");
        }
        puts(
            "\n+-------+----------+----------+-----------------+-------------------------------------+"
            );
      }
    }
  }
  return;
}

