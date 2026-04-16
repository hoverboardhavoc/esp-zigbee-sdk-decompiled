/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zcl_scenes_table_show(uint8_t ep_id)

{
  int *piVar1;
  byte *pbVar2;
  undefined3 in_register_00002029;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar3 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),5,1,0xeff1,0x131b);
  if (iVar3 != 0) {
    pbVar5 = *(byte **)(iVar3 + 8);
    puts("+-------+----------+----------+-----------------+-------------------------------------+");
    puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extension Field]    |");
    puts("+-------+----------+----------+-----------------+-------------------------------------+");
    pbVar2 = pbVar5 + 8;
    for (iVar3 = 0; iVar3 < (int)(uint)*pbVar5; iVar3 = iVar3 + 1) {
      if (*pbVar2 != 0) {
        printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
        for (piVar1 = *(int **)(pbVar2 + 0x1c); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
          printf(" [ 0x%04x |");
          if ((*(char *)((int)piVar1 + 6) != '\0') && (piVar1[2] != 0)) {
            for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)((int)piVar1 + 6); iVar4 = iVar4 + 1) {
              printf(" 0x%x ");
            }
          }
          printf("] |");
        }
        puts(
            "\n+-------+----------+----------+-----------------+-------------------------------------+"
            );
      }
      pbVar2 = pbVar2 + 0x20;
    }
  }
  return;
}

