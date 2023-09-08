/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_table_show
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_table_show(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  puts("| Index | Group ID | Scene ID | Transition Time |   [Cluster ID | Extendsion Field]   |");
  puts("+-------+----------+----------+-----------------+-------------------------------------+");
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    if ((&esp_zb_zcl_scenes_table)[iVar3 * 6] != -1) {
      printf("|   %02d  |  0x%04x  |   0x%02x   |      %04d       |");
      for (iVar1 = (&DAT_000158e8)[iVar3 * 3]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
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

