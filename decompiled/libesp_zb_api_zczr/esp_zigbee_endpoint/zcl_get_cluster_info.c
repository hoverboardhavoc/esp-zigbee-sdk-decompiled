/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> zcl_get_cluster_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * zcl_get_cluster_info(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  pcVar1 = (char *)calloc(1,4);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar2,0x10000);
    pcVar1 = (char *)0x0;
  }
  else {
    while (param_1 = *(int *)(param_1 + 0x10), param_1 != 0) {
      *pcVar1 = *pcVar1 + '\x01';
      if (*(char *)(param_1 + 8) == '\x01') {
        pcVar1[2] = pcVar1[2] + '\x01';
      }
      else {
        pcVar1[3] = pcVar1[3] + '\x01';
      }
      iVar3 = *(int *)(param_1 + 4);
      for (uVar4 = 0; uVar4 < *(ushort *)(param_1 + 2); uVar4 = uVar4 + 1 & 0xffff) {
        if ((*(byte *)(uVar4 * 8 + iVar3 + 3) & 4) != 0) {
          pcVar1[1] = pcVar1[1] + '\x01';
        }
      }
    }
  }
  return pcVar1;
}

