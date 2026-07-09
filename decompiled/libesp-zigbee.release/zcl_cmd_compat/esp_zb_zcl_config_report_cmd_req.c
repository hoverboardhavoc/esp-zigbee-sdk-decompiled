/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_config_report_cmd_req(int param_1)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *__s;
  void *__ptr;
  int iVar6;
  size_t __n;
  uint uVar7;
  undefined1 auStack_44 [28];
  ushort uStack_28;
  void *pvStack_24;
  
  memset(auStack_44,0,0x24);
  if (((param_1 != 0) && (*(ushort *)(param_1 + 0x12) != 0)) && (*(int *)(param_1 + 0x14) != 0)) {
    uVar7 = 0;
    __ptr = malloc((uint)*(ushort *)(param_1 + 0x12) * 0x18);
    if (__ptr != (void *)0x0) {
      for (; uVar2 = *(ushort *)(param_1 + 0x12), uVar7 < uVar2; uVar7 = uVar7 + 1 & 0xffff) {
        pcVar5 = (char *)(*(int *)(param_1 + 0x14) + uVar7 * 0x10);
        __s = (char *)(uVar7 * 0x18 + (int)__ptr);
        memset(__s,0,0x18);
        cVar1 = *pcVar5;
        *__s = cVar1;
        *(undefined2 *)(__s + 2) = *(undefined2 *)(pcVar5 + 2);
        if (cVar1 == '\0') {
          cVar1 = pcVar5[4];
          *(undefined2 *)(__s + 10) = *(undefined2 *)(pcVar5 + 6);
          uVar3 = *(undefined2 *)(pcVar5 + 8);
          __s[8] = cVar1;
          *(undefined2 *)(__s + 0xc) = uVar3;
          if (((*(int *)(pcVar5 + 0xc) != 0) && (iVar6 = ezb_zcl_attr_type_is_analog(), iVar6 != 0))
             && (__n = ezb_zcl_get_attr_value_size(pcVar5[4],*(undefined4 *)(pcVar5 + 0xc)),
                (__n - 1 & 0xffff) < 8)) {
            memcpy(__s + 0x10,*(void **)(pcVar5 + 0xc),__n);
          }
        }
        else {
          *(undefined2 *)(__s + 8) = *(undefined2 *)(pcVar5 + 4);
        }
      }
      convert_to_ezb_general_cmd_ctrl(auStack_44,param_1);
      uStack_28 = uVar2;
      pvStack_24 = __ptr;
      iVar6 = ezb_zcl_config_report_cmd_req(auStack_44);
      uVar4 = 0xff;
      if (iVar6 == 0) {
        uVar4 = zcl_get_current_tsn();
      }
      free(__ptr);
      return uVar4;
    }
  }
  return 0xff;
}

