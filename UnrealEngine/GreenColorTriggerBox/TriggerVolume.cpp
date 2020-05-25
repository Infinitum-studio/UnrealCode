#include "TriggerVolume.h"

#define print(text if(GEngine) GEngine->AddOnScreenDebugMessage(-1,1.5,FColor:Green, FString::
Printf(Text(text), fstring));

#include "MyTriggerBox.h"
#include "DrawDebugHelpers.h"

AMyTriggerBox::AMyTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
}

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void AMyTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

	if (OtherActor && (OtherActor != this))
	{
		print("OverlapBegin")
			printf("Overlapped Actor =%s", *OverlappedActor->GetName());

	}


}

void AMyTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{

	if (OtherActor && (OtherActor != this))
	{
		print("OverlapEnded")
			printf("Overlapped Actor =%s", *OtherActor->GetName());

	}


}
