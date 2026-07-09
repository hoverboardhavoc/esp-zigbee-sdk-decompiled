/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_match_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_match_desc_req(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_38 [20];
  int iStack_24;
  
  memset(auStack_38,0,0x18);
  if ((param_1 == (undefined2 *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    iVar2 = 2;
    goto _L0;
  }
  iVar1 = zdo_packet_init(auStack_38,6,*param_1,*(undefined4 *)(param_1 + 8),
                          *(undefined4 *)(param_1 + 10));
  iVar2 = -1;
  if (iVar1 != 0) goto _L0;
  if (iStack_24 == 0) {
    __assert_func(0,0,0);
_L0:
    iVar2 = zmsg_append_le16(iStack_24,param_1[3]);
    if (iVar2 == 0) {
      uVar3 = 0;
      iVar2 = zmsg_append_u8(iStack_24,*(undefined1 *)(param_1 + 4));
      if (iVar2 == 0) {
        for (; uVar3 < *(byte *)(param_1 + 4); uVar3 = uVar3 + 1 & 0xff) {
          iVar2 = zmsg_append_le16(iStack_24,*(undefined2 *)(*(int *)(param_1 + 6) + uVar3 * 2));
          if (iVar2 != 0) goto _L0;
        }
        iVar2 = zmsg_append_u8(iStack_24,*(undefined1 *)((int)param_1 + 9));
        uVar3 = 0;
        if (iVar2 == 0) {
          for (; uVar3 < *(byte *)((int)param_1 + 9); uVar3 = uVar3 + 1 & 0xff) {
            iVar2 = zmsg_append_le16(iStack_24,
                                     *(undefined2 *)
                                      ((*(byte *)(param_1 + 4) + uVar3) * 2 + *(int *)(param_1 + 6))
                                    );
            if (iVar2 != 0) goto _L0;
          }
          zdo_packet_send(auStack_38);
          iVar2 = zdp_status_to_err();
          if (iVar2 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
    }
  }
  else {
    iVar2 = zmsg_append_le16(iStack_24,param_1[2]);
    if (iVar2 == 0) goto _L0;
  }
_L0:
  iVar2 = 1;
_L0:
  zdo_packet_free(auStack_38);
  return iVar2;
}

