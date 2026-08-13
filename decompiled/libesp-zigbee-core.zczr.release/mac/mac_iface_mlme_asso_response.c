/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_asso_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_iface_mlme_asso_response(undefined4 *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *__src;
  undefined2 uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined1 auStack_50 [2];
  undefined1 auStack_4e [8];
  undefined1 uStack_46;
  undefined1 auStack_44 [8];
  undefined1 auStack_3c [2];
  undefined1 auStack_3a [34];
  
  __src = (void *)*param_1;
  iVar2 = zmsg_alloc(0);
  iVar1 = 1;
  if (iVar2 != 0) {
    memset(auStack_3c,0,0x1c);
    auStack_50[0] = 3;
    memcpy(auStack_4e,__src,8);
    uStack_46 = 3;
    memcpy(auStack_44,param_2,8);
    uStack_54 = *(undefined2 *)((int)__src + 10);
    uStack_52 = uStack_54;
    uVar3 = mac_frame_write_hdr(auStack_3c,auStack_50,&uStack_54,0,3,2);
    iVar1 = zmsg_append_bytes(iVar2,uVar3,auStack_3c);
    if (iVar1 == 0) {
      uStack_56 = *(undefined2 *)((int)param_2 + 8);
      iVar1 = zmsg_append_bytes(iVar2,2,&uStack_56);
      if (iVar1 == 0) {
        uStack_56 = CONCAT11(uStack_56._1_1_,*(undefined1 *)((int)param_2 + 10));
        iVar1 = zmsg_append_bytes(iVar2,1,&uStack_56);
        if (iVar1 == 0) {
          auStack_3c[0] = 3;
          memcpy(auStack_3a,param_2,8);
          mac_indirect_transmit(__src,auStack_3c,iVar2);
          return 0;
        }
      }
    }
    zmsg_free(iVar2);
  }
  return iVar1;
}

