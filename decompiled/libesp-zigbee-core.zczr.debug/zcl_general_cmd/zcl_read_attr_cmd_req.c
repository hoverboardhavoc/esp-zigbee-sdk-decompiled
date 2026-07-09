/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_read_attr_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else if (*(char *)(param_1 + 0x1c) == '\0') {
    iVar1 = 2;
  }
  else if (*(int *)(param_1 + 0x20) == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,*(uint *)(param_1 + 0x10) & 1);
    if (iVar1 == 0) {
      uVar3 = *(uint *)(param_1 + 0x10);
      iVar2 = zcl_cmd_to_packet(&uStack_38,0,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                                *(undefined2 *)(param_1 + 0xe),0,*(undefined2 *)(param_1 + 0xc));
      iVar1 = iVar2;
      if (iVar2 == 0) {
        while ((iVar2 < (int)(uint)*(byte *)(param_1 + 0x1c) && (*(int *)(param_1 + 0x20) != 0))) {
          uStack_3a = *(undefined2 *)(*(int *)(param_1 + 0x20) + iVar2 * 2);
          iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3a);
          if (iVar1 != 0) goto _L0;
          iVar2 = iVar2 + 1;
        }
        zcl_packet_send(&uStack_38,param_1 + 0x14);
        iVar1 = zcl_status_to_err();
_L0:
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar1;
}

