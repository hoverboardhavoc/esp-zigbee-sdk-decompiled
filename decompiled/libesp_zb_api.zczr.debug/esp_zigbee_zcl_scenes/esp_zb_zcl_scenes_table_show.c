/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_show(uint param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extension Field]   |");
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  for (iVar4 = 0; iVar4 < (int)(uint)esp_zb_zcl_scenes_table_capacity; iVar4 = iVar4 + 1) {
    pbVar3 = (byte *)(esp_zb_zcl_scenes_table + iVar4 * 0xc);
    if ((*pbVar3 == param_1) && (*(short *)(pbVar3 + 2) != -1)) {
      printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
      for (iVar1 = *(int *)(esp_zb_zcl_scenes_table + iVar4 * 0xc + 8); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 8)) {
        printf(" [ 0x%04x |");
        if ((*(char *)(iVar1 + 2) != '\0') && (*(int *)(iVar1 + 4) != 0)) {
          for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)(iVar1 + 2); iVar2 = iVar2 + 1) {
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
  return;
}

