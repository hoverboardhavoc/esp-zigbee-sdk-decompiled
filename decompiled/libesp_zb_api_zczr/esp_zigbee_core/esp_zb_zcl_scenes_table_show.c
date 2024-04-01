/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_show(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extendsion Field]   |");
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  pbVar1 = &esp_zb_zcl_scenes_table;
  iVar3 = 0;
  do {
    if ((*pbVar1 == param_1) && (*(short *)(pbVar1 + 2) != -1)) {
      printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
      for (iVar2 = *(int *)(pbVar1 + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        printf(" [ 0x%04x |");
        if ((*(char *)(iVar2 + 2) != '\0') && (*(int *)(iVar2 + 4) != 0)) {
          for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)(iVar2 + 2); iVar4 = iVar4 + 1) {
            printf(" 0x%x ");
          }
        }
        printf("] |");
      }
      puts(
          "\n+-------+----------+----------+-----------------+-------------------------------------+"
          );
    }
    iVar3 = iVar3 + 1;
    pbVar1 = pbVar1 + 0xc;
  } while (iVar3 != 0x10);
  return;
}

