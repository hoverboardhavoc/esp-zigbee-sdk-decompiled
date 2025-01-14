/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
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
  int iVar3;
  
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extension Field]   |");
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    if (((byte)(&esp_zb_zcl_scenes_table)[iVar2 * 0xc] == param_1) &&
       ((&DAT_00012c7e)[iVar2 * 6] != -1)) {
      printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
      for (iVar1 = (&DAT_00012c84)[iVar2 * 3]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
        printf(" [ 0x%04x |");
        if ((*(char *)(iVar1 + 2) != '\0') && (*(int *)(iVar1 + 4) != 0)) {
          for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(iVar1 + 2); iVar3 = iVar3 + 1) {
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

