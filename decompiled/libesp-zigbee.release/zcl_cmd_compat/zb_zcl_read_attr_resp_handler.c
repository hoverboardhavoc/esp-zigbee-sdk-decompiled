/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_read_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_read_attr_resp_handler(undefined1 *param_1,code *param_2)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_44 [32];
  undefined1 *puStack_24;
  
  memset(auStack_44,0,0x24);
  convert_to_esp_zb_zcl_cmd_info(auStack_44,*(undefined4 *)(param_1 + 8));
  auStack_44[0] = *param_1;
  puVar1 = *(undefined2 **)(param_1 + 0xc);
  do {
    if (puVar1 == (undefined2 *)0x0) {
_L0:
      if (param_2 != (code *)0x0) {
        (*param_2)(1,auStack_44);
        uVar2 = esp_err_to_zcl_status();
        param_1[0x10] = uVar2;
      }
      while (puStack_24 != (undefined1 *)0x0) {
        puVar4 = *(undefined1 **)(puStack_24 + 0x10);
        free(puStack_24);
        puStack_24 = puVar4;
      }
      return;
    }
    puVar4 = (undefined1 *)malloc(0x14);
    if (puVar4 == (undefined1 *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","read attr resp: malloc failed");
      goto _L0;
    }
    *puVar4 = *(undefined1 *)(puVar1 + 1);
    uVar5 = *(undefined4 *)(puVar1 + 2);
    *(undefined2 *)(puVar4 + 4) = *puVar1;
    *(undefined4 *)(puVar4 + 0xc) = uVar5;
    puVar4[8] = *(undefined1 *)((int)puVar1 + 3);
    uVar3 = ezb_zcl_get_attr_value_size();
    puVar1 = *(undefined2 **)(puVar1 + 4);
    *(undefined2 *)(puVar4 + 10) = uVar3;
    *(undefined1 **)(puVar4 + 0x10) = puStack_24;
    puStack_24 = puVar4;
  } while( true );
}

