/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_publish_tier_labels_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void price_cluster_publish_tier_labels_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uStack_46;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  uint uStack_24;
  
  uStack_44 = 0;
  uStack_40 = 0;
  iStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uStack_24 = 0;
  uStack_46 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x118,
                  "price_cluster_publish_tier_labels_cmd_handler","packet && rsp");
  }
  else {
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_46,&uStack_38);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_46,&uStack_34);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_46,&uStack_30);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_46,&uStack_2c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_46,(int)&uStack_2c + 1);
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_46,(int)&uStack_2c + 2);
    if (iVar1 != 1) {
      uVar2 = 0x80;
      goto _L0;
    }
    uVar2 = uStack_2c >> 0x10 & 0xff;
    if (uVar2 != 0) {
      pvStack_28 = calloc(uVar2,0xe);
      if (pvStack_28 == (void *)0x0) {
        uVar2 = 0x89;
        goto _L0;
      }
      for (uVar2 = 0; uVar2 < (uStack_2c >> 0x10 & 0xff); uVar2 = uVar2 + 1 & 0xff) {
        iVar1 = uVar2 * 0xe;
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_46,(void *)((int)pvStack_28 + iVar1));
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_46,(int)pvStack_28 + iVar1 + 1);
        if (0xc < *(byte *)((int)pvStack_28 + iVar1 + 1)) {
          uVar2 = 0x87;
          goto _L0;
        }
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),&uStack_46,(int)pvStack_28 + iVar1 + 2);
      }
    }
  }
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < uStack_46) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(&uStack_44,param_1);
    if (uVar2 == 0) {
      uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
      iStack_3c = param_1;
      zcl_core_action_schedule(0x50,&uStack_44);
      if ((uStack_24 & 0xff) != 0xfe) {
        uVar2 = uStack_24 & 0xff;
      }
    }
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

