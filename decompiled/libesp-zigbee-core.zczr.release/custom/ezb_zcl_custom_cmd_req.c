/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> custom.o -> ezb_zcl_custom_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_custom_cmd_req(void *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,0);
    iVar1 = 1;
    if (iVar2 == 0) {
      memcpy(auStack_50,param_1,10);
      uVar3 = *(uint *)((int)param_1 + 0x10);
      iVar1 = zcl_cmd_to_packet(auStack_38,1,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                                *(undefined2 *)((int)param_1 + 0xe),
                                *(undefined1 *)((int)param_1 + 0x1c),
                                *(undefined2 *)((int)param_1 + 0xc));
      if ((iVar1 == 0) &&
         (iVar1 = zmsg_append_bytes(uStack_14,*(undefined2 *)((int)param_1 + 0x1e),
                                    *(undefined4 *)((int)param_1 + 0x20)), iVar1 == 0)) {
        zcl_packet_send(auStack_38,(int)param_1 + 0x14);
        iVar1 = zcl_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

