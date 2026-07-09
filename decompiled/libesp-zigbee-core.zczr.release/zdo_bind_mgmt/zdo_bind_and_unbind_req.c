/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_and_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_bind_and_unbind_req(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uStack_2a;
  undefined1 auStack_28 [20];
  int iStack_14;
  
  memset(auStack_28,0,0x18);
  if (param_2 == (undefined2 *)0x0) {
    iVar1 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,param_1,*param_2,*(undefined4 *)(param_2 + 0xe),
                          *(undefined4 *)(param_2 + 0x10));
  iVar1 = -1;
  if (iVar2 != 0) goto _L0;
  if (iStack_14 == 0) {
    __assert_func(0,0,0);
_L0:
    uStack_2a = CONCAT11(uStack_2a._1_1_,*(undefined1 *)(param_2 + 5));
    iVar1 = zmsg_append_bytes(iStack_14,1,&uStack_2a);
    if (iVar1 == 0) {
      uStack_2a = param_2[6];
      iVar1 = zmsg_append_bytes(iStack_14,2,&uStack_2a);
      if (iVar1 == 0) {
        uStack_2a = CONCAT11(uStack_2a._1_1_,*(undefined1 *)(param_2 + 7));
        iVar1 = zmsg_append_bytes(iStack_14,1,&uStack_2a);
        if (iVar1 == 0) {
          if (*(char *)(param_2 + 7) != '\x03') {
            if (*(char *)(param_2 + 7) == '\x01') {
              uStack_2a = param_2[8];
              uVar3 = 2;
              goto _L0;
            }
_L0:
            zdo_packet_send(auStack_28);
            iVar1 = zdp_status_to_err();
            if (iVar1 == 0) {
              return 0;
            }
            goto _L0;
          }
          iVar1 = zmsg_append_bytes(iStack_14,8,param_2 + 8);
          if (iVar1 == 0) {
            uVar3 = 1;
            uStack_2a = CONCAT11(uStack_2a._1_1_,*(undefined1 *)(param_2 + 0xc));
_L0:
            iVar1 = zmsg_append_bytes(iStack_14,uVar3,&uStack_2a);
            if (iVar1 == 0) goto _L0;
          }
        }
      }
    }
  }
  else {
    iVar1 = zmsg_append_bytes(iStack_14,8,param_2 + 1);
    if (iVar1 == 0) goto _L0;
  }
  iVar1 = 1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

