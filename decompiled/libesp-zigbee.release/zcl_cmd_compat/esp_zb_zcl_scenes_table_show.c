/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_show(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar3 = ezb_zcl_get_attr_desc(5,1,0xeff1,0x131b);
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

